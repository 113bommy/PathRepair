def main():
    a = int(input())
    for i in range(a):
        temp = int(input())
        values = list(filter(lambda x: x <= 2048, map(int, input().split())))
        if len(values) is 0:
            print('NO')
            return
        values = sorted(values, reverse=True)
        decide = True
        while(True):
            if values[0] == 2048:
                print('YES')
                break
            elif decide == False:
                print('NO')
                break
            decide = False
            i = 0
            while i < len(values) - 1:
                if values[i] == values[i+1]:
                    decide = True
                    values[i] = values[i] + values[i+1]
                    del values[i+1]
                i += 1
 
if __name__ == '__main__':
    main()
