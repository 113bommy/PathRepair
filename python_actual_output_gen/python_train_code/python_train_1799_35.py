n=input()
print("Four" if len(set(map(int,input().split())))==4 else "Three")