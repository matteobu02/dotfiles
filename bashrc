export PATH="/usr/local/bin/:$PATH"
export BASH_SILENCE_DEPRECATION_WARNING=1
export LSCOLORS="ExFxCxDxBxegedabagaced"

force_color_prompt=yes

if [ $(id -u) -eq 0 ];
then
	PS1='\[\033[01;31m\]\u\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\] # '
else
	PS1='\[\033[01;32m\]\u\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\] $ '
fi

export PS1

alias gcl='git clone'
alias py='python3'
alias cp='cp -r'
alias rm='rm -rf'
alias rma='rm a.out'
alias vim='/usr/bin/nvim'
alias grep='grep --color=auto'

# Docker aliases
alias ddown='docker-compose down -v --rmi all --remove-orphans'
alias doup='docker-compose up -d'

# dotfiles
alias vrc='vim ~/.vimrc'
alias brc='vim ~/.bashrc'


# ls aliases
alias la='ls -la'
alias ll='ls -l'
alias ls='ls --color=auto'
