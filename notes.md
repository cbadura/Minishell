### MINISHELL NOTES ###

# TODO
- signal handling
- exit status with $? (use echo $?)
	https://stackoverflow.com/questions/27306764/capturing-exit-status-code-of-child-process
- echo1 test
- '            test'
- fix `echo -n12313 foobar`
- handle `export` with no argument(declare -x)
- function that interprets $
- lexer: handle space? echo 123"456"     789

# READLINE
- how to display history?

# STATES
The bash parser works with states, e.g. when a " is read. This triggers a quoted state for all characters that follow up until the next quote of the same type. If the quoted state was triggered by a double quote ("..."), all characters except for $ lose any special meaning they might have. That includes single quotes, spaces and newlines, etc. If the quoted state was triggered by a single quote ('...'), all characters except for ' lose their special meaning. Yes, also $.
IN THIS PROJECT: single quotes ignore all metacharacters, double quotes all but $.

# PARSING / LEXING
- read line
- process quotes
- check for pipes/redirections and store the status along with filename
- parameter expansion (for $parameter)
- split into commands: Bash basically cuts the command line into pieces wherever it sees whitespace. This whitespace is completely removed and the pieces are called words. Whitespace in this context means: Any spaces, tabs or newlines that are not escaped. (Escaped spaces, such as spaces inside quotes, lose their special meaning of whitespace and are not used for splitting up the command line. They appear literally in the resulting arguments.)
- execution:  If the command type is a function or builtin, the command is executed by the same Bash process that just went through all these steps. Otherwise, Bash will first fork off (create a new bash process), initialize the new bash processes with the settings that were parsed out of this command (redirections, arguments, etc.) and execute the command in the forked off bash process (child process). The parent (the Bash that did these steps) waits for the child to complete the command. 

# SPECIAL COMMANDS & CHARACTERS

# BUILTINS

# LOG
22-3	Cosmo	added environment variable related
23-3	Cosmo	added ft_strcmp to libft

27-3	Chris	linked list for normal vars in data struct (e.g. var=hello) -> expanding part still needed (for e.g. echo $var)

28-3	Cosmo	added ft_strtok to libft
28-3	Cosmo	general function to call a env var

29-3	Cosmo	basic prototype of lexer