s = input()
o = s.count('o')
m = s.count('-')
if o == 1:
    print("YES")
else:
    if not m:
        print("YES")
    else:
        if not o:
            print("YES")
        else:
            if m == 1:
                print("NO")
            else:
                if o > m:
                    print("NO")
                else:
                    if o % m == 0:
                        print("YES")
                    else:
                        print("NO")













