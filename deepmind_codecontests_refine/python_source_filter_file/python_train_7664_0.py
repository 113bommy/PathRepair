import sys

entries = {}
records = []

for line in sys.stdin.readlines():
    records += [line.replace('\n', '').split(" ")]

records = records[1:]
#print(records)

def check_if_suffixed(s1, s2):
    if len(s1) >= len(s2):
        extra = len(s1) - len(s2)
        if s1[extra:] == s2:
            return s1
    elif len(s1) < len(s2):
        extra = len(s2) - len(s1)
        if s2[extra:] == s1:
            return s2
    return False

def arr_filter(lon):
    result = []
    for ph in lon:
        #print(ph)
        to_add = True
        for (i,a) in enumerate(result):
            #print(i, a)
            r = check_if_suffixed(ph, a)
            #print(r)
            if (r == False):
                pass
            elif (r == ph):
                to_add = False
                result[i] = ph
            elif (r == a):
                to_add = False
            else:
                pass
                #print(r)
        if (to_add):
            result.append(ph)
    return result

for record in records:
    name = record[0]
    num_ph = record[1]
    if name not in entries:
        entries[name] = []
        for ph in arr_filter(record[2:]):
            #print('PH:', ph)
            entries[name].append(ph)
    elif name in entries:
        for ph in (record[2 : ]):
            to_add = True
            for (i , ph2) in enumerate(entries[name]):
                r = check_if_suffixed(ph, ph2)
                #print(r, ph, ph2)
                if (r == False):
                    pass
                else:
                    entries[name][i] = r
                    to_add = False
                ##print(entries[name])
            if (to_add):
                entries[name].append(ph)

#print(entries)


print(len(entries))
for name, phs in entries.items():
    out = '{0} {1} '.format(name, len(entries[name]))
    for i,e in enumerate(entries[name]):
        out += e
        if i < len(entries[name]) - 1:
            print('test', i)
            out += ' '
    #out += '/'
    print(out)
