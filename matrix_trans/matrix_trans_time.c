#include <stdio.h>
#include <time.h>
#include <stdlib.h>

size_t N = 16384;
size_t M = 16384;
size_t RECUR_MIN = 8;
size_t BLOCK = 1024;

void trance(size_t* in_, size_t* out_){
    for(size_t i=0;i<N;++i){
        for(size_t j=0;j<M;++j){
            out_[j*N+i] = in_[i*M+j];
        }
    }
}

void recur(size_t* in_, size_t* out_, size_t start_x, size_t end_x, size_t start_y, size_t end_y){
    if(end_x - start_x >= RECUR_MIN){
        size_t diff = (end_x - start_x)/2;
        recur(in_, out_, start_x, start_x+diff, start_y, end_y);
        recur(in_, out_, start_x+diff, end_x, start_y, end_y);
    }else if(end_y - start_y >= RECUR_MIN){
        size_t diff = (end_y - start_y)/2;
        recur(in_, out_, start_x, end_x, start_y, start_y+diff);
        recur(in_, out_, start_x, end_x, start_y+diff, end_y);
    }else{
        for(size_t i=start_x;i<end_x;++i){
            for(size_t j=start_y;j<end_y;++j){
                out_[j*N+i] = in_[i*M+j];
            }
        }
    }
}

void block(size_t* in_, size_t* out_){
    for(size_t i=0;i<N;i+=BLOCK){
        for(size_t j=0;j<M;j+=BLOCK){
            for(size_t ii=0;ii<=BLOCK;++ii){
                for(size_t jj=0;jj<=BLOCK;++jj){
                    out_[jj*N+ii] = in_[ii*M+jj];        
                }
            }
        }
    }
}

int main(int argc, char**argv){
    int ope = 0;
    if(argc > 1){
        ope = atoi(argv[1]);
    }
    if(argc > 2){
        N = atoi(argv[2]);
    }
    printf("N: %lu\n", N);
    if(argc > 3){
        M = atoi(argv[3]);
    }
    printf("M: %lu\n", M);
    if(argc > 4){
        RECUR_MIN = atoi(argv[4]);
    }
    printf("RECUR_MIN: %lu\n", RECUR_MIN);
    if(argc > 5){
        BLOCK = atoi(argv[5]);
    }
    printf("BLOCK: %lu\n", BLOCK);
    
    size_t* in = (size_t*)malloc(N*M*sizeof(size_t));
    size_t* out = (size_t*)malloc(N*M*sizeof(size_t));

    for(size_t i=0;i<N;++i){
        for(size_t j=0;j<M;++j){
            in[i*M+j] = i*j;
        }
    }

    clock_t start_clock, end_clock;
    start_clock = clock();
    if(ope == 0){
        printf("trance\n");
        trance(in, out);
    }else if (ope == 1){
        printf("recur\n");
        recur(in, out, 0, N, 0, M);
    }else if (ope == 2){
        printf("block\n");
        block(in, out);
    }
    end_clock = clock();
    printf("clock:%f\n", (double)(end_clock - start_clock) / CLOCKS_PER_SEC);   
    free(in);
    free(out);
}