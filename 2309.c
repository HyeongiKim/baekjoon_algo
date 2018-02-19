#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int arr[], int left, int right)
{
    int pivot = arr[(left + right)/2];
    int i = left;
    int j = right;

    while (i <= j){

        while (arr[i] < pivot){i++;}

        while (arr[j] > pivot){j--;}

        if (i <= j){
            //tmp = arr[i];
            //arr[i] = arr[j];
            //arr[j] = tmp;
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main()
{
    int i, idx, cur, dwarf, comb_sum, sum;
    int _a,_b,_c,_d,_e,_f,_g,_h,_i;
    int height[9], ans[7];
    char comb[36][9];
    for (i=0;i<9;i++){
        scanf("%d",&dwarf);
        height[i] = dwarf;
    }
    // Find combination n(9,7)
    idx=0;
    for (_a=0;_a<2;_a++){
        for (_b=0;_b<2;_b++){
            for (_c=0;_c<2;_c++){
                for (_d=0;_d<2;_d++){
                    for (_e=0;_e<2;_e++){
                        for (_f=0;_f<2;_f++){
                            for (_g=0;_g<2;_g++){
                                for (_h=0;_h<2;_h++){
                                    for (_i=0;_i<2;_i++){
                                        comb_sum = _a + _b + _c + _d + _e + _f + _g + _h + _i;
                                        if (idx == 36) break;
                                        if (comb_sum == 7){
                                            comb[idx][0] = _a;
                                            comb[idx][1] = _b;
                                            comb[idx][2] = _c;
                                            comb[idx][3] = _d;
                                            comb[idx][4] = _e;
                                            comb[idx][5] = _f;
                                            comb[idx][6] = _g;
                                            comb[idx][7] = _h;
                                            comb[idx][8] = _i; 
                                            idx++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sum = 0;
    for (idx=0;idx<36;idx++){
        for (i=0;i<9;i++){
            if (comb[idx][i]==1){
                sum += height[i];
            }
        }
        if (sum == 100){
            cur = 0;
            for (i=0;i<9;i++){
                if (comb[idx][i]==1){
                    ans[cur] = height[i];
                    cur++;
                }
            }
            break;
        }
        else{
            sum = 0;
        }
    }
    quicksort(ans,0,6);
    for (i=0;i<7;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
