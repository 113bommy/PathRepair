def test(n,string,index):
    if(len(n)==1):
        if(string[index]==n[0]):
            return 1
        else:
            return 0
    else:
        tag = n[:len(n)//2].count(string[index])
        tag1 = n[len(n)//2:].count(string[index])
        sum1 = len(n)//2-tag+test(n[len(n)//2:],string,index+1)
        sum2 = len(n)//2-tag1+test(n[:len(n)//2],string,index+1)
        return min(sum1,sum2)
    
a = input()
for x in range(int(a)):
    c = input()
    b = input()
    ans = 0
    string = "abcdefghijklmnopqrstuvwxyz"
    print(test(b,string,0))