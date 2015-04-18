#include<iostream>
using namespace std;
class Solution {
public:
    int total;
    double rec(int A[],int m,int B[],int n,int k){
        if(m==0){
            int tmp=n-total;
            if((n-total)%2==1){
                return B[tmp/2];
            }
            else{
                return (double(B[tmp/2])+double(B[tmp/2-1]))/2;                
            }
        }
        if(n==0){
            int tmp=m-total;
            if((m-total)%2==1)
                return A[tmp/2];
            else{
                return (double(A[tmp/2])+double(A[tmp/2-1]))/2;                
            }

        }
        if(k==1){
            if(m+n==2)
                return (double(A[0])+double(B[0]))/2;
            /*else if(m+n==3){
                if(m==2){
                    if(A[0]<B[0]<A[1]){
                        return B[0];
                    }
                    if(A[0]<A[1]<B[0]){
                        return A[1];
                    }
                    if(B[0]<A[0]){
                        return A[0];
                    }
                }
                if(n==2){
                    if(B[0]<A[0]<B[1]){
                        return A[0];
                    }
                    if(A[0]<B[0]<B[1]){
                        return B[0];
                    }
                    if(B[1]<A[0]){
                        return B[1];
                    }                    
                }

            }*/
        }
        if(m>k/2-1 and n>k/2-1){
            if(A[k/2-1]<B[k/2-1]){
                total+=k/2;
                rec(A+int(k/2),m-int(k/2),B,n,int((m+n)/2));
            }
            else if(A[int(k/2)-1]>B[int(k/2)-1]){
                total+=k/2;
                rec(A,m,B+int(k/2),n-int(k/2),int((m+n)/2));
            }
            else{
               if((m+n)%2==1)
                    return ((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]);
                else if((m+n)%4==0)
                    return (double(B[k/2-1])+((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]))/2;
                else{
                    return (double(B[k/2])+double(A[k/2]))/2;
                }
            }
        }
        else if(m<k/2){
            if(A[m]<B[int(k/2)-1]){
                total+=k/2;
                rec(A,0,B,n,int((m+n)/2));
            }
            else if(A[m]>B[int(k/2)-1]){
                total+=k/2;
                rec(A,m,B+int(k/2),n-int(k/2),int((m+n)/2));
            }
            else{
                if((m+n)%2==1)
                    return ((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]);
                else if((m+n)%4==0)
                    return (double(B[k/2-1])+((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]))/2;
                else{
                    return (double(B[k/2])+double(A[k/2]))/2;
                }
            }            
        }
        else if(n<k/2){
            if(A[int(k/2)-1]<B[n]){
                total+=k/2;
                rec(A+int(k/2),m-int(k/2),B,n,int((m+n)/2));
            }
            else if(A[int(k/2)-1]>B[n]){
                total+=k/2;
                rec(A,m,B,0,int((m+n)/2));
            }
            else{
                if((m+n)%2==1)
                    return ((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]);
                else if((m+n)%4==0)
                    return (double(B[k/2-1])+((A[k/2]<B[k/2]) ? A[k/2]:B[k/2]))/2;
                else{
                    return (double(B[k/2])+double(A[k/2]))/2;                    
                }
                
            }          
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        total=0;
        return rec(A,m,B,n,(m+n)/2);

    }
};
int main(){
    Solution sol;
    int* a=new int[1];
    int* b=new int[2];
    a[0]=1;
    b[0]=2;
    b[1]=3;
    cout<<sol.findMedianSortedArrays(a ,1, b, 2);

    return 0;
}