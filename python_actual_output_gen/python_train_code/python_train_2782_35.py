n=input()
l=len(n)
a="90909"[:l-1]
print(a if l %2 ==0 else int(n)-int(a))