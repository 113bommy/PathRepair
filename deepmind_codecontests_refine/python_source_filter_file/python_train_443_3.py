t = int(input())
# indexs = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
import math
for _ in range(t):
    n,k = map(int,input().split())
    x = n/math.sqrt(2)/k
    # print(int(x)**2,int(x+1)**2,(n/k)**2)
    print("Ashish" if int(x)**2+int(x+1)**2<(n/k)**2 else "Utkarsh")