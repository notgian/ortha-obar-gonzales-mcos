# Using Git
For the purposes of our project, whether you will use the cli to do this or not, this is generally what you need to know about Git and GitHub 

## GIT != GITHUB
Just to make sure we are all on the same page, Git is not one and the same with GitHub. Git is to GitHub as videos are to Youtube. Git is a version control system, which lets us see and track the changes we make to the code, even allowing us to work on different "branches." GitHub is just a place online where the Git repository is hosted. To use the repository, these are generally the main operations and terms that you need to know: 

## Commit
When you make changes to the files, git doesn't automatically save them. You need to tell them when to save a version of these files. This is what a commit is. Think of it like the different previous versions of a GDocs file. Each one is like a separate commit. Commits also come with a message that allows you to briefly describe the changes you made. It is recommended that you make a commit any time that you make any significant changes. You can commit changes without using git from the command line by pressing the **ADD FILE** button beside the green **CODE** button on the GitHub repository's page. There you can upload new/edited versions of the files. Add a message for this, and make sure that you don't commit it to main when working on a separate feature. Use a branch, which I will explain in the next section.

## Branches
Git repositories can have different branches. Think of each branch as a separate sort of feature. For example, we have the main branch, where the finalized code will eventually end up, but while we work on different features (sort, modified sort, vector implementations, the algorithim itself) they can have a different branch where the feature is worked on separately. On the github repository, you have two options to create a branch: (1) when you choose to upload files, there will be an option to create a new branch with that commit [only do this for *new* features] and (2) by clicking on the branches button [you should see this on the same row in the UI as the big green **CODE** button. It will say *n branches* just click that and the page will give you an option to create a new branch*

## Merge
You may see a message to greate a pull request/merge into some branch. DO NOT DO IT WILLY NILLY. Merging is basically when you take the commits and changes from one branch and merge them into another branch. This does not destroy the previous branch or anything, but it's just used to combine the feature from one branch into another. You don't have to worry about it for now.

## Using the CLI (only if you want to)

If you really want to use the CLI, here's a general overview of how:

### Clone the git
First, make sure to change directory (cd) into where you want the repo to go then run <br />
<code>git clone https://github.com/notgian/ortha-obar-gonzales-mco1.git</code> <br />
This creates a copy of the repository on your system. Take note that when doing this, any local changes and commits to your LOCAL repository are not reflected onto our github, or the repository's REMOTE HEAD. I'll get back to that later.

### Adding and Committing
Commits using the cli work a little bit differently. Git does not immediately know which files to track for changes and which ones to commit, so before committing any changes you need to tell git what files to track. You have the option of listing each filename manually or just using a period (**.**) to denote all files in the current directory.

<br /> <code> git add . </code> OR <code> git add filename.extension </code> <br />

### Pushing to the Remote Head
Since all changes to the local repository don't immediately reflect onto the our remote repo on GitHub, you need to push the changes of the current branch to the remote head. When pushing to a branch for the first time, you need to tell git where to push it to, so you run 
<br /> <code>git push origin branch-name</code> <br />
Afaik, subsequent pushes to the git don't need the origin part since the git knows which branch to push to, however, when pushing to another new branch, you need to run the command with the origin part of it again.
