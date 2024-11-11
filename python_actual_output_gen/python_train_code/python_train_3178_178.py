k=int(input())
s=input()
print(s[:k+1]+"{0}".format("..."*(len(s)>k)))