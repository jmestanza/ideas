strings = {}
example_hash = []

def hash(curr):
    return sum([ord(el) for el in curr])

for i in range(14):
    curr = input()
    strings[curr] = i
    example_hash.append(hash(curr))

strings[""] = 15
example_hash.append(hash(""))
print(strings)
print(example_hash)

for k in example_hash:
    print(k%16)

