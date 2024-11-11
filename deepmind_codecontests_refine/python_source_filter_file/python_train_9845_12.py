n=int(input())
s=input()
print("Friendship" if s.count('A')==n else "Anton" if s.count('A')>n/2 else "Danik")