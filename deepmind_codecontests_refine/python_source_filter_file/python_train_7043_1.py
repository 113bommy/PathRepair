# D - Single-use Stones

w,l = [int(i) for i in input().split(' ')]
a = [1.1E6]*(w+1)

entrada = [int(i) for i in input().split(' ')]
for i in range (1, w):
    a[i] = entrada[i-1]


aux = [0]*len(a)


num = 0
for j in range (1, w+1):
    if(a[j] <= 0):
        continue
    if(j <= l):
        aux[j] = a[j]
        continue
    d = j
    for k in range(j - l, d):
        if(aux[k] < (a[j] - aux[j])):
            num = aux[k]
        else:
            num = a[j] - aux[j]
        aux[k] = aux[k] - num
        aux[j] = aux[j] + num
        if(aux[j]>= a[j]):
            break

print(aux[-1])

# print (w)
# print (l)
# print (a)

#############CPP################
  
#include <cstdio>
#include <vector>



# int main(){

#     long w, l; scanf("%ld %ld", &w, &l);
#     std::vector<long> a(w + 1, 2e9); 
#     for(long p = 1; p < w; p++){scanf("%ld", &a[p]);}
#     std::vector<long> b(w + 1, 0);

#     for(long p = 1; p <= w; p++){
#         if(a[p] <= 0){continue;}
#         if(p <= l){b[p] = a[p]; continue;}
#         for(long u = p - l; u < p; u++){
#             long num = (b[u] < (a[p] - b[p])) ? b[u] : (a[p] - b[p]);
#             b[u] -= mv; b[p] += mv;
#             if(b[p] >= a[p]){break;}
#         }
#     }

#     printf("%ld\n", b.back());

#     return 0;
# }