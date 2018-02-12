#! /bin/bash
set -e

# Add bash aliases to zshrc
if [ -f "$HOME/.zshrc" ]; then
	cat $HOME/.bash_aliases >> $HOME/.zshrc
fi

# Add QTcreator alias command
if [ -d "$HOME/Qt" ]; then
	qt_alias="alias qtcreator=$HOME/Qt/Tools/QtCreator/bin/qtcreator"
	echo "$qt_alias" >> $HOME/.bash_aliases
	echo "$qt_alias" >> $HOME/.zshrc
fi

exec "$@"

