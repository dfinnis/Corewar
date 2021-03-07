# Corewar

[Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game in which two or more fighting programs compete for control of a virtual computer.

The goal of this project was to create:

* A Champion (fighting program), written in assembly.

* An Assembler ```asm```, which compiles the champion assembly into bytecode.

* A Virtual Machine ```corewar```, the battle arena where champions fight to the death.

#### Final Score 125/100


## Getting Started

First clone this repo to your machine.

```git clone https://github.com/dfinnis/Corewar.git; cd Corewar```

Make the binaries asm and corewar.

```make```

Run the virtual machine with assembled champions. You'll find some assembled champions in champions/compiled/.

```./corewar champions/the_best_player_around_the_whole_universe.cor champions/compiled/zork.cor```

![simple](https://github.com/dfinnis/Corewar/blob/master/img/simple.gif)

Our champion (the_best_player_around_the_whole_universe) beat Zork!


## Virtual Machine



### Flags




## Assembler

```asm```

Assemble champions from assembly (.s) to bytecode (.cor).

```./asm```

### Flags





## Champion

the_best_player_around_the_whole_universe

(anti-zork)


## Team

[@svaskeli](https://github.com/sharvas) & I created the Virtual Machine.

[@erli](https://github.com/dracoeric) & @pmasson created the Assembler.
