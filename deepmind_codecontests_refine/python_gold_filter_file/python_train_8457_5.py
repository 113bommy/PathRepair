T = int(input())
for _ in range(T):
 
    n = int(input())
    a1 = list(map(int,input().split()))
    a2 = list(map(int,input().split()))
    print("No" if a2.count(1)%n == 0 and a1 != sorted(a1) else "Yes") 
 