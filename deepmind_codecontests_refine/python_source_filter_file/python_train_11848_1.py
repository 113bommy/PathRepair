N=int(input())
A,B= list(map(int,input().split())),list(map(int,input().split()))

ans = 0
for i,b in enumerate(B):
    temp = min(b,A[i]+A[i+1])
    ans += temp
    A[i+1] -= max(0, temp-A[i]) #有り余った力を次の街で倒す
print(an)
