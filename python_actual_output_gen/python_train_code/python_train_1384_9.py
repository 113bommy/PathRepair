s=input()
t=input()

if s==t:
    print("0")
elif len(s)==len(t):
    print(len(s))
else:
    print(max(len(s),len(t)))