def find_it(b):
    lists  = [i.strip() for i in b[1:-1].split(",")]
    dict = {}
    for i in lists:
        if i:
            if not i in dict:
                dict[i] = 1
            else:
                dict[i] += 1
    return dict


b = input()
print(find_it(b))