n = int(input())
a = ['','ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']; b = ['','one','two','three','four','five','six','seven','eight','nine']; c = ['','elleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
if n==0:
    print("zero")
elif n % 100 >10 and n % 100 <20:
    print(c[(n%100)-10])
else:
    d = n//10; e = n%10;
    if e==0:
        print(a[d])
    elif d == 0:
        print(b[e])
    else:
        print("%s-%s" %(a[d], b[e]))