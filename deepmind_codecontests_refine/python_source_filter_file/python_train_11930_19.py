from math import ceil
n,t,k,d = map(int, input().split())
print("YES" if(ceil(n/k)*t > t) else "NO")
#Aloosh