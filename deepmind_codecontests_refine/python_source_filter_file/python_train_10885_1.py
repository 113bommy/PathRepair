def parse(string):
    parts = int(string.replace(".", ""))
    if len(string) < 3 or string[-3] != ".":
        parts *= 100
    return parts

def out(string):
    #print(string)
    to_print = []
    if string[-2:] == ".0":
        string = string[:-2]
    elif string[-3:] == ".000":
        string = string[:-3]
    if len(string) > 2 and string[-2] == ".":
        to_print.append("0" + string[-1])
        string = string[:-2]
    elif len(string) > 3 and string[-3] == ".":
        to_print.append(string[-2] + string[-1])
        string = string[:-3]
    string = string[::-1]
    for i in range(0, len(string ) - len(string) % 3, 3):
        to_print.append(string[i:i+3][::-1])
    to_print.append(string[len(string ) - len(string) % 3:][::-1])
    if "" in to_print:
        del to_print[to_print.index("")]
    print(*to_print[::-1], sep=".")


cheque = input()
res = 0
now_number = []
now_state = 0
for i in cheque:
    if i in "abcdefghijklmnopqrstuvwxyz" and now_state == 1:
        now_state = 0
        res += parse("".join(now_number))
        now_number = []
    if i in "0123456789.":
        now_number.append(i)
        now_state = 1
res += parse("".join(now_number))
#print(res)
#print((str(res / 100)+ "0" * (2 - len(str(res/100)[str(res / 100).index(".") + 1]))))
out(str(res / 100)+ "0" * (2 - len(str(res/100)[str(res / 100).index(".") + 1:])))