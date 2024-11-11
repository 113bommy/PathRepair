from sys import stdin, stdout  

def main():
    s, t = input(), input()
    res = list(s)
    carry = True
    i = len(s) - 1

    while i > 0 and carry:
        if res[i] == 'z':
            carry = True
            res[i] = 'a'
        else:
            res[i] = chr(ord(res[i]) + 1)
            carry = False
        i -= 1
    res = ''.join(res)
    print(res if res != t else "No such string")



if __name__ == "__main__":
    main()