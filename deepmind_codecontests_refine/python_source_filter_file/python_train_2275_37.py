n = int(input())
l = list(map(int,input().split()))
m = [i%2 for i in l]
print("YNEOS"[l.count(1)%2==0::2])