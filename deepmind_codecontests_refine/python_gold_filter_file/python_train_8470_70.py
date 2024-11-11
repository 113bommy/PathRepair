n=int(input())
n+=1
def test(x):
    x=set(str(n))
    if len(x)!=4:
        return True

while(test(n)):
    n+=1
print(n)

