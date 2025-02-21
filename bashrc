# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# Load starship prompt if starship is installed
if  [ -x /usr/bin/starship ]; then
    __main() {
        local major="${BASH_VERSINFO[0]}"
        local minor="${BASH_VERSINFO[1]}"

        if ((major > 4)) || { ((major == 4)) && ((minor >= 1)); }; then
            source <("/usr/bin/starship" init bash --print-full-init)
        else
            source /dev/stdin <<<"$("/usr/bin/starship" init bash --print-full-init)"
        fi
    }
    __main
    unset -f __main
fi

export PATH="/usr/local/bin/:$PATH"
export BASH_SILENCE_DEPRECATION_WARNING=1
export LSCOLORS="ExFxCxDxBxegedabagaced"

# Replace ls with exa (comment if exa not installed)
alias ls='exa --color=always --group-directories-first' # preferred listing
alias la='exa -la --color=always --group-directories-first'  # all files and dirs
alias ll='exa -l --color=always --group-directories-first'  # long format
alias lt='exa -aT --color=always --group-directories-first' # tree listing
alias l.='exa -ald --color=always --group-directories-first .*' # show only dotfiles

alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias .....='cd ../../../..'
alias ......='cd ../../../../..'
alias py='python3'
alias cp='cp -r'
alias rm='rm -rf'
alias rma='rm a.out'
alias vim='/usr/bin/nvim'
alias grep='grep --color=auto'
alias ip='ip -color'
alias disas='objdump --disassembler-color=on -d -Mintel'
alias asm='nasm -felf64'

export EDITOR=vim

# git aliases
alias gcl='git clone'
alias gst='git status'

# dotfiles
alias vrc='vim ~/.config/nvim'
alias brc='vim ~/.bashrc'

# ls aliases
alias la='ls -la'
alias ll='ls -l'
alias ls='ls --color=auto'
