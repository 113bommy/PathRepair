n=input()
l=len(n)
a="090909"[:l]
print(a[1:] if l %2 ==0 else int(n)-int(a))