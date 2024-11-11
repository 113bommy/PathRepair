n = int(input())
#lst_in = str_in.split('\n')
s = str(input())

decrypt = ['' for i in range(len(s))]
pointer = 0
for i in range(11):
    for j in range(i):
        if pointer >= len(s):
            break
        print(i)
        decrypt[i-1] = s[pointer]
        pointer += 1
print(''.join(decrypt).strip())
