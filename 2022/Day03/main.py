# import array as arr

def ex01(lines):
    prioritySum = 0
    for line in lines:
        size = int(len(line) / 2)
        string1, string2 = line[0:size], line[size:]
        commonchar = set(string1).intersection(string2)
        for item in commonchar:
            if item.islower():
                prioritySum += ord(item) - ord('a') + 1
            else:
                prioritySum += ord(item) - ord('A') + 27

    print("ex01: ", prioritySum)


def ex02(lines):
    team = []
    prioritySum = 0
    for i, line in enumerate(lines):
        if i % 3 == 0:
            team.clear()
        team.append(line)
        if i > 0 and i % 3 == 2:
            common = set(team[0]) & set(team[1]) & set(team[2])
            for item in common:
                if item.islower():
                    prioritySum += ord(item) - ord('a') + 1
                else:
                    prioritySum += ord(item) - ord('A') + 27

    print("ex02: ", prioritySum)


def __main__():
    input = open("input.txt", 'r')
    lines = input.read().splitlines()
    ex01(lines)
    ex02(lines)


__main__()
