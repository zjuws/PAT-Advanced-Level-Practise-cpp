#include <stdio.h>
#include <string.h>

char mya[50];

long long gcd(long long a,long long b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

struct fraction {
    long long a,b,k;
    int sign;
}ft[6];

void reads(char *s,fraction* f) {
    sscanf(s,"%lld/%lld",&f->a,&f->b);
    f->sign = 1;
    if(f->a<0) {
        f->a*=-1;
        f->sign*=-1;
    }
}

void yuefen(fraction *f) {
    long long g = gcd(f->a,f->b);
    f->a/=g;
    f->b/=g;
}

void* sprint(fraction * f) {
    //char mya[50];
    if(f->b==0) {
        sprintf(mya,"Inf");
        return mya;
    }

    char tmp[50];

    strcpy(mya,"");

    f->k+=f->a/f->b;
    f->a%=f->b;

    if(f->sign<0) strcat(mya,"(-");

    if(f->k!=0) {
        sprintf(tmp,"%lld",f->k);
        strcat(mya, tmp);
    }

    if(f->a!=0) {
        if(f->k!=0) strcat(mya, " ");
        sprintf(tmp,"%lld/%lld",f->a,f->b);
        strcat(mya, tmp);
    }

    if(f->sign<0) strcat(mya,")");

    if(strlen(mya) == 0) strcpy(mya,"0");

    return mya;
}

int main()
{
    char a[50],b[50];
    while(scanf("%s%s",a,b)!=EOF){
        reads(a,&ft[0]);
        reads(b,&ft[1]);
        char ans[6][50];
        for(int i=0;i<2;i++){
            yuefen(&ft[i]);
        }
        for(int i=0;i<6;i++){
            ft[i].k=0;
        }

        ft[2].a=ft[0].sign*ft[0].a*ft[1].b+ft[1].sign*ft[1].a*ft[0].b;
        ft[2].b=ft[0].b*ft[1].b;

        ft[3].a=ft[0].sign*ft[0].a*ft[1].b-ft[1].sign*ft[1].a*ft[0].b;
        ft[3].b=ft[0].b*ft[1].b;

        ft[4].a=ft[1].sign*ft[0].sign*ft[0].a*ft[1].a;
        ft[4].b=ft[0].b*ft[1].b;

        ft[5].a=ft[1].sign*ft[0].sign*ft[0].a*ft[1].b;
        ft[5].b=ft[0].b*ft[1].a;

        for(int i=2;i<6;i++) {
            if(ft[i].a<0) {
                ft[i].a*=-1;
                ft[i].sign=-1;
            }
            else {
                ft[i].sign=1;
            }
            if(ft[i].b!=0){
                yuefen(&ft[i]);
            }
        }

        for(int i=0;i<6;i++) {
            sprint(&ft[i]);
            strcpy(ans[i],mya);
        }

        printf("%s + %s = %s\n",ans[0],ans[1],ans[2]);
        printf("%s - %s = %s\n",ans[0],ans[1],ans[3]);
        printf("%s * %s = %s\n",ans[0],ans[1],ans[4]);
        if(ft[5].b==0) printf("%s / %s = Inf\n",ans[0],ans[1]);
        else printf("%s / %s = %s\n",ans[0],ans[1],ans[5]);
    }
    return 0;
}