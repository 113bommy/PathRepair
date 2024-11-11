n = int(input())
l = list(map(int,input().split()))
m = [i%2 for i in l]
print("YNeos"[l.count(1)%2==0::2])