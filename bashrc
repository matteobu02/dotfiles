export PATH="~/.emacs.d/bin:$PATH"
export PATH="/usr/local/opt/ruby/bin:$PATH"
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
alias e="emacsclient -ca 'emacs'"
alias compile='cc -Wall -Wextra -Werror'
alias norm='norminette -R CheckForbiddenSourceHeader'
alias c+='c++ -Wall -Wextra -Werror'
alias rm='rm -rf'
alias rma='rm a.out'

# Color terminal output
alias ls='ls --color=auto'
alias grep='grep --color=auto'

alias la='ls -la'
alias ll='ls -l'
alias cp='cp -r'
