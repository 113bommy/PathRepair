def check(word, symbols, refer):
    word_new, w_n = word, word
    for s in symbols:
        if s in word:
            w_n = w_n.replace(s, '')
            word_new = word_new + w_n
        else: return False
    if refer != word_new: return False
    return True

for _ in range(int(input())):
    t = input()
    t_set = set(t)
    if len(t_set) == 0:
        print('')
    elif len(t_set) == 1:
        print(t, list(t_set)[0])
    else:
        symbols = ''.join(sorted(t_set, key=t.rindex))
        symbolcount_dict = dict.fromkeys(list(symbols))
        for i, symbol in enumerate(symbols, 1):
            key_val = t.count(symbol) / i
            if key_val % 1 != 0:
                print(-1)
                break
            symbolcount_dict[symbol] = key_val
        else:
            i, word = 0, ''
            flag = False
            while not flag:
                try:
                    symbolcount_dict[t[i]] = symbolcount_dict[t[i]] - 1
                except:
                    print(t)
                    break
                word = word + t[i]
                try:
                    flag = all(val == 0 for val in symbolcount_dict.values())
                except:
                    print('All')
                    break
                i += 1
            else:
                if check(word, symbols, t):
                    print(word, symbols)
                else:
                    print(-1)
