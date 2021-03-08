# Corewar

[Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game in which two or more fighting programs compete for control of a virtual computer.

The goal of [this project](https://github.com/dfinnis/Corewar/blob/master/subject.pdf) was to create:

* A Champion (fighting program), written in assembly.
* An Assembler ```asm```, which compiles the champion assembly into bytecode.
* A Virtual Machine ```corewar```, the battle arena where champions fight to the death.

#### Final Score 125/100


## Getting Started

First clone this repo to your machine.

```git clone https://github.com/dfinnis/Corewar.git; cd Corewar```

Make the binaries asm and corewar.

```make```

Run the virtual machine with 2-4 assembled champions as argument. You'll find some assembled champions in champions/compiled/.

```./corewar champions/the_best_player_around_the_whole_universe.cor champions/compiled/zork.cor```

![simple](https://github.com/dfinnis/Corewar/blob/master/img/simple.gif)

Our champion (the_best_player_around_the_whole_universe) beat Zork, great!


## Virtual Machine

Champions are loaded into the circular virtual memory battle arena. The game ends when *cycle_to_die* reaches 0, or when all processes are dead. The last to have been reported alive wins.

Some strategies:
* Aim to execute *live* last.
* *fork* to create more processes who work for you.
* Overwrite enemy bytecode, evicerating or enslaving them.

### Flags

#### -v, vizualizer

* -v [speed (1-100)], plays the game start to end without *-w* or *-dump*.
* -cp, color process pointers according to which champion it works for (rather than spawned).
* -w nbr_cycles, wait *nbr_cycles* before starting vizualizer.
* -dump nbr_cycles, dump virtual machine state *nbr_cycles* into game. In combination with *-w* a specific period of the game can be viewed.

We can view just the crucial moment in the game where our champion overwrites zork, after which zork calls *live* for our champion.

```./corewar champions/the_best_player_around_the_whole_universe.cor champions/compiled/zork.cor -v -cp -w 2150 -dump 2400```

![v](https://github.com/dfinnis/Corewar/blob/master/img/v.gif)

#### end

* -a, don't print *alive* operations (as prescribed by the subject). Much cleaner output.
* -e, print cycle_count at end (how long the game is).

```./corewar champions/the_best_player_around_the_whole_universe.cor champions/compiled/zork.cor -a -e```

<img src="https://github.com/dfinnis/Corewar/blob/master/img/ae.png">

#### debugging

* -op, print operations excecuted & argument sizes.
* -arg, print values extracted from the coding byte.


## Champion

Our champion (the_best_player_around_the_whole_universe) was written to beat zork.

Our champion calls *alive*, forks itself and overwrites zork's id number with our champions id number.
Zombie zork now calls *alive* for our champion, zork is defeated.

<img src="https://github.com/dfinnis/Corewar/blob/master/img/champion.png" width="75%">

Above .s assembly, below .cor assembled bytecode.

<img src="https://github.com/dfinnis/Corewar/blob/master/img/champion2.png" width="75%">


## Assembler

Run the assembler with one or more champion.s files as argument. The assembler assembles .s assembly to .cor bytecode, ready to be loaded into the VM. You'll find some champion.s files in champions/uncompiled/.

```./asm champions/the_best_player_around_the_whole_universe.s```

<img src="https://github.com/dfinnis/Corewar/blob/master/img/asm.png" width="80%">

If the .s file is invalid, asm displays detailed error messages specifying line and column number in the assembly file.

### Flags

* -o <dest>, specify destination folder (default same as sourcefile).
* -c, remove filesize limit.


## Team

[@svaskeli](https://github.com/sharvas) & I created the Virtual Machine.

[@erli](https://github.com/dracoeric) & @pmasson created the Assembler.
