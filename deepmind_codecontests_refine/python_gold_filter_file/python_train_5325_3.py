kk=lambda:map(int,input().split())
ll=lambda:list(kk())
n,s=int(input()),ll()
print("Bob" if s.count(min(s)) > n/2 else "Alice")