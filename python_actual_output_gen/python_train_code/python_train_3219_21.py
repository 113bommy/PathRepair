K, A, B = map(int, input().split())

if(B-A <= 2):
    print(K+1)
else:
    m = max(0, K-(A-1)//2)*(B-A)+(K+1)-2*max(0, K-(A-1)//2)
    print(m)