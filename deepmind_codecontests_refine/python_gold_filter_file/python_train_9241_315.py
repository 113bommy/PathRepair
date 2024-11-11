k=int(input())
s=input()
print(s[:k]+"{0}".format("..."*(len(s)>k)))