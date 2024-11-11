# your code goes here
# Bulbasaur
import sys

def main():
    news = input()
    # print(news)
    dic = make_dict(news)
    count = catch_bulb(dic)
    print(count)

def make_dict(news):
    dic = {}
    for s in news:
        if s in dic:
            dic[s] += 1
        else:
            dic[s] = 1
    return dic

def catch_bulb(dic):
    # print(dic)
    count = 0
    while ('B' in dic and dic['B'] >= 1) and ('u' in dic and dic['u'] > 1) and ('l' in dic and dic['l'] >= 1) and ('b' in dic and dic['b'] >= 1) and ('a' in dic and dic['a'] > 1) and ('s' in dic and dic['s'] >= 1) and ('r' in dic and dic['r'] >= 1):
        count += 1
        dic['B'] -= 1
        dic['u'] -= 2
        dic['l'] -= 1
        dic['b'] -= 1
        dic['a'] -= 2
        dic['s'] -= 1
        dic['r'] -= 1
    return count

if __name__ == '__main__':
    main()
