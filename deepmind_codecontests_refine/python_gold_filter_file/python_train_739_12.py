
def answer(n, a):
    #print('n=', n, 'a=', a)
    for j in range(0, 2**n):
        summ = 0
        bj = bin(j)[2:].zfill(n)
        #print('bj=', bj)
        for i in range(n):
            #print('i=', i, 'bj[i]=', bj[i], 'a[i]=', a[i])
            if bj[i] == '0':
                summ += a[i]
            else:
                summ -= a[i]
        if summ % 360 == 0:
            return 'YES'
            

    return 'NO'

def main():
    n = int(input())
    a = []
    for j in range(n):
        a.append(int(input()))
    print(answer(n, a))


    return
main()