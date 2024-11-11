a=int(input())
x=list(map(int,input().split()))
b=(lambda i: i if i>(sum(x)/a)*2 else i+1)(round(sum(x)/a)*2)
print(max(b,max(x)))
#author:SK__Shanto__㋛
#code__define__your__smartness