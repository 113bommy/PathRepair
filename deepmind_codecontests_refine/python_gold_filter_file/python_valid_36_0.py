
for _ in range(int(input())):
    n=int(input())
    print('a' if n==1 else 'a'*(n//2)+('bc' if n%2 else 'b')+'a'*(n//2-1))