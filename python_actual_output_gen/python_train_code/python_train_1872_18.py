N= int(input())
L= list(map(int, input().split()))
print("YNeos"[max(L)*2>sum(L)::2])