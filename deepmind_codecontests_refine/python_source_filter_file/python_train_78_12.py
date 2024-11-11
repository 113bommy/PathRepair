n=int(input())
def d(s):
    if len(s)==n:print(s)
    else:for i in range(97,ord(max(s))+2):d(s+chr(i))
d("a")