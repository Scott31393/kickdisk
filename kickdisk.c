#include <stdio.h>
#include <stdlib.h>

struct __attribute__((__packed__)) mbr_t{
    unsigned char mbr[446];
};

struct __attribute__((__packed__)) gpt_t{
    unsigned char gpt_p1[16];
    unsigned char gpt_p2[16];
    unsigned char gpt_p3[16];
    unsigned char gpt_p4[16];
    unsigned char gpt_end[2];
};

struct __attribute__((__packed__)) sctr1_t{
    struct gpt_t gpt;
    struct mbr_t mbr;
};

int main(void){
    struct mbr_t *mbr;
    struct gpt_t *gpt;
    struct sctr1_t *sctr1;
    FILE *f_ptr;

    mbr = (struct mbr_t *) malloc(sizeof(mbr->mbr));
    gpt = (struct gpt_t *) malloc(sizeof(gpt));
    sctr1 =(struct sctr1_t *) malloc(sizeof(sctr1));

    printf("sizeof gpt_t = %d \n", (int) sizeof(*gpt));
    printf("sizeof mbr_t = %d \n", (int) sizeof(*mbr));
    printf("sizeof sctr1_t = %d \n", (int) sizeof(*sctr1));

    f_ptr = fopen("test1-fat-32","rb");
    fread(sctr1,sizeof(sctr1),1,f_ptr);

    for(int i = 0; i<16; i++)
        printf("%x ",sctr1->gpt.gpt_p1[i]);

    return 0;
}

//alelr78@virgilio.it