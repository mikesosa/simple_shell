<!DOCTYPE html>
<html lang="en">
	<body>
			<article>
				<h1>
					Building our own Shell (Shellita)
				</h1>
				<h2>
					Introduction
				</h2>
				<p>Description</p>
				<p>We (<a href="https://twitter.com/micael_sosa">Michael Sosa</a> and <a href="https://twitter.com/micael_sosa">Daniel Rodriguez</a>) wrote our own simple version of shell. All the outputs and exit statuses should return the same as sh's. This project focused on memory, sys calls, pointer, structures, dynamic memory allocation etc. It took us 10 days with 2 daily hours of work in average, there were limitations in the usage of some functions.</p>
				<h2>
					Description of Each Directory
				</h2>
				<hr>
				<table>
					<thead>
						<tr>
							<th>Directory</th>
							<th>Description</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td><code>_strtok.c</code></td>
							<td>Our own version of strtok which tokenizes any string passed as argument with a delimiter.</td>
						</tr>
						<tr>
							<td><code>builtin.c</code></td>
							<td>Contains all the builtins functions like "env, cd, exit, history etc".</td>
						</tr>
						<tr>
							<td><code>env.c</code></td>
							<td>Function in charge of getting the global enviroment and pass it to our shell.</td>
						</tr>
						<tr>
							<td><code>exec.c</code></td>
							<td>Executes a function after it finds the rigth path of it.</td>
						</tr>
						<tr>
							<td><code>main.c</code></td>
							<td>Main function when we control every subfunction for execution of the program.</td>
						</tr>
						<tr>
							<td><code>memory.c</code></td>
							<td>In charge of freeing the memory and setting it to zero.</td>
						</tr>
					</tbody>
				</table>
				<hr>
				<h3>
					Examples and Usage
				</h3>
				<ul>
					<li>Language: C, Bash</li>
					<li>Operating System: Ubuntu 14.04 LTS (Trusty64)</li>
					<li>Style: Holberton Betty</li>
					<li>Compiler: gcc 4.8.4 with flags -Wall -Werror -Wextra -pedantic</li>
					<li>Version Control: Git</li>
				</ul>
				<hr>
				<h3>
					Technologies Used
				</h3>
				<ul>
					<li>Language: C, Bash</li>
					<li>Operating System: Ubuntu 14.04 LTS (Trusty64)</li>
					<li>Style: Holberton Betty</li>
					<li>Compiler: gcc 4.8.4 with flags -Wall -Werror -Wextra -pedantic</li>
					<li>Version Control: Git</li>
				</ul>
				<hr>
				<h3>
					Authors Social Media
				</h3>
				<p>Michael Sosa <a href="https://www.linkedin.com/in/michael-sosa/" rel="nofollow">Linkedin</a> || <a href="https://twitter.com/micael_sosa" rel="nofollow">Twitter: @micael_sosa</a></p>
				<p>Daniel Rodriguez <a href="https://www.linkedin.com/in/dr2d4/" rel="nofollow">Linkedin</a> || <a href="https://twitter.com/dr2d4" rel="nofollow">Twitter: @dr2d4</a></p>
				<hr>
			</article>
	</body>
</html>
