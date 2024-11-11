a, b = map(int,(input()).split())
while True:
    if a==0 or b==0: break
    elif a>=(2*b): a = a%b
    elif b>=(2*a): b = b%a
    else: break
print(a,b)