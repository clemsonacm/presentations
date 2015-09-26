# Clemson ACM Seminar Presentations

TODO. Make note here of where to view presentations.

## Presentation Descriptions

TODO

## Deployment Instructions

Deploying these presentations is very easy! How much work you'll have to do depends on what aspects of the project you want to work on.

For future reference, the command that you will want to use to *clone* this repository is:

    git clone --recursive https://github.com/clemsonacm/seminars.git

### ...for Viewing

Perhaps you wish to read or show one of these presentations. They are not currently mirrored anywhere, but they will be soon.

Generally speaking, you can view any presentation like this, once it is hosted:

    http://wherever.your.host.is/seminar-folder?seminar-name

If someone with the username `ama2` had checked out the seminars to their Clemson web hosting in a folder called `seminars`, you would visit this URL to get the Git presentation:

    http://people.cs.clemson.edu/~ama2/seminars?git

How's that work? `index.html` dynamically loads markdown files into the presentation based on the `?seminar-name` (the `location.search` variable) part of the URL. Accessing `?git` loads the file `sources/git/git.md`. 

#### On your Clemson web hosting

1. After logging in via SSH or a lab terminal, visit your Clemson web hosting folder at `/web/home/$USER/public_html`. If you don't already have one, you may want to follow the **Web Site** instructions at [the UNIX help desk](http://www.cs.clemson.edu/help/unixaccount.html) page.
2. Clone this repository with `git clone --recursive https://github.com/clemsonacm/seminars.git`
3. Run `chown -R o+r <folder>` to fix your permissions.
4. Done! Try it out by accessing `http://people.cs.clemson.edu/~YOUR-USERNAME/seminars?git`

#### Other Places

You will need a way to *host* these files. You cannot simply open the files in your web browser.

1. Clone this repository with `git clone --recursive https://github.com/clemsonacm/seminars.git`.
2. If you have a hosting solution already (hosting from a web server, etc.), you're done!
3. If you don't have Python installed, go install Python. Python 2 and 3 will both work.
4. `cd seminars`
5. Run Python's quick HTTP server.
   - For Python 2: `python -m SimpleHTTPServer`
   - For Python 3: `python -m http.server`
6. Open `0.0.0.0:8000` and add `?an-existing-seminar-name` to test things out. You're done!

### ...for Editing Content

All you have to do after setting the presentations up for viewing is to edit the markdown and refresh the page. You probably don't even have to touch `index.html`.

### ...for Editing Style

Changing the seminar theme is a little bit more involved, but still pretty easy.

TODO

## Markdown Style Guidelines

TODO. Note: Three empty lines delimits slides; two empty lines delimits a downwards slide.
