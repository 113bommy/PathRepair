for _ in range(int(input())):
    n=int(input())
    s=input()
    print(n//2-(s.count('01')+s.count('10')))