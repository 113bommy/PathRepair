N = int(input())
As = list(map(int,input().split()))
As1 = [a-(i+1) for i,a in enumerate(As)]
m = sorted(As1)[len(As)//2]

f = [abs(a-m) for a in As1]
print(sum(f))