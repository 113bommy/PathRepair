N = int(input())
L = list(map(int,input().split()))
print("YNeos"[max(L) >= sum(L)-max(L)::2])