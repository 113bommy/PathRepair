import sys

if __name__ == "__main__":

    n = int(sys.stdin.readline())
    l = sys.stdin.readline().strip('\n').split(' ')

    l.sort()
    count = 1
    aux = 1

    for j in range(1,n):
        if l[j-1] == l[j]:
            count+=1


            if count>aux:
                aux = count
            continue

        else:
            count = 0

    print (aux)