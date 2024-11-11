n = int(input())
p = int(pow(n,0.5))
div = []
prime = 0
for i in range(2,p+1):
    if n % i == 0 :
        div.append(i)
        #print(i,n/i)
        for j in range(2,int(pow(i,0.5)+1)):
            if i%j==0:
                break
        else:
            prime += 1
        m = int(n/i)
        #print(m,i,m!=i)
        if m!=i:
            for j in range(2,int(pow(m,0.5))+1):
                if m%j==0:
                    print(j)
                    break
            else:
                prime += 1
    if prime == 2:
        print(1)
        break
else:
    if div == []:
        print(n)
    else:
        print(min(div))
#(prime)