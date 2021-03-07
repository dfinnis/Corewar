# Corewar

[Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game in which two or more fighting programs compete for control of a virtual computer.

The goal of this project was to create:

* A Champion (fighting program), written in assembly.

* An Assembler ```asm```, which compiles the champion assembly into bytecode.

* A Virtual Machine ```corewar```, the battle arena where champions battle.

#### Final Score 125/100


## Getting Started

First clone this repo to your machine.

```git clone https://github.com/dfinnis/Corewar.git; cd Corewar```

Make the binaries asm and corewar.

```make```

And run the virtual machine with assembled champions.

```./corewar champions/the_best_player_around_the_whole_universe.cor champions/compiled/zork.cor```



## Assembler

```asm```

Assemble champions from assembly (.s) to bytecode (.cor).

```./asm```

### Flags

## Virtual Machine


## Champion

the_best_player_around_the_whole_universe

(anti-zork)

### Flags


## Team

[@svaskeli](https://github.com/sharvas) & I created the Virtual Machine.

[@erli](https://github.com/dracoeric) & @pmasson created the Assembler.
